// 노트: 개같음


#include <stdio.h>
#include <stdbool.h>

int main()
{
    int R, C;
    char grid[41][41];

    while (scanf("%d %d", &R, &C) == 2)
    {
        if (R == 0 && C == 0)
            break;

        for (int i = 0; i < R; i++)
        {
            scanf("%s", grid[i]);
        }

        // bounding boxes: for each letter present
        int min_r[26], max_r[26], min_c[26], max_c[26];
        // present letters: whether a letter is present in the grid
        bool present[26] = {0};
        // reset bounding boxes
        for (int k = 0; k < 26; k++)
        {
            min_r[k] = R;
            max_r[k] = -1;
            min_c[k] = C;
            max_c[k] = -1;
        }

        // find bounding box
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                char ch = grid[i][j];
                if (ch >= 'a' && ch <= 'z')
                {
                    // idx: set to the letter's index in the alphabet
                    int idx = ch - 'a';
                    // update bounding box for this letter
                    present[idx] = true;
                    // update min/max rows and columns
                    if (i < min_r[idx])
                        min_r[idx] = i;
                    if (i > max_r[idx])
                        max_r[idx] = i;
                    if (j < min_c[idx])
                        min_c[idx] = j;
                    if (j > max_c[idx])
                        max_c[idx] = j;
                }
            }
        }

        // build direct "above" relation: above[x][y] means x is above y
        bool above[26][26] = {0};
        // check each letter's bounding box for other letters inside
        for (int y = 0; y < 26; y++)
        {
            // if letter is not present, skip
            if (!present[y])
                continue;
            // check the bounding box of letter y
            for (int i = min_r[y]; i <= max_r[y]; i++)
            {
                for (int j = min_c[y]; j <= max_c[y]; j++)
                {
                    char ch = grid[i][j];
                    // check character - '.'
                    if (ch >= 'a' && ch <= 'z')
                    {
                        int x = ch - 'a';
                        // if not the same letter and present
                        if (x != y)
                        {
                            // x is above y if it appears in the bounding box of y
                            above[x][y] = true;
                        }
                    }
                }
            }
        }

        // update "above" relation to include indirect relations
        // transitive closure (Floyd-Warshall: if i is above k and k is above j, mark i above j
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                if (!present[i])
                    continue;
                if (!above[i][k])
                    continue;
                for (int j = 0; j < 26; j++)
                {
                    if (above[k][j])
                        above[i][j] = true;
                }
            }
        }

        printf("Uncovered: ");

        // all alphabet loop
        for (int l = 0; l < 26; l++)
        {
            // if letter is not present, skip
            if (!present[l])
                continue;

            // set paper to the letter
            char paper = 'a' + l;

            // check 1. bounding rectangle contains any other letter inside?
            bool partially_covered = false;
            for (int i = min_r[l]; i <= max_r[l] && !partially_covered; i++)
            {
                for (int j = min_c[l]; j <= max_c[l]; j++)
                {
                    if (grid[i][j] != paper)
                    {
                        partially_covered = true;
                        break;
                    }
                }
            }
            if (partially_covered)
                continue;

            // check 2. check all four directions for extension
            bool can_be_extended = false;

            // Check if the bounding box of letter 'l' can be extended UP
            int row = min_r[l] - 1; // one row above the top of the box

            if (row >= 0)
            {                    // make sure we're not out of bounds
                int blocked = 0; // assume not blocked yet

                // scan all columns from left to right across the top stripe
                for (int c = min_c[l]; c <= max_c[l]; c++)
                {
                    char ch = grid[row][c]; // get the character above the box

                    if (ch == '.')
                    {
                        // an empty cell means we can't extend here
                        blocked = 1;
                    }

                    if (ch >= 'a' && ch <= 'z')
                    {
                        int z = ch - 'a'; // get index of the letter found
                        if (above[l][z])
                        {
                            // if 'l' is above 'z', then 'z' is under 'l' => can't extend
                            blocked = 1;
                        }
                    }
                }

                // if the whole stripe is clean (no block), then it can be extended
                if (!blocked)
                    can_be_extended = true;
            }

            // Check DOWN
            row = max_r[l] + 1;
            if (!can_be_extended && row < R)
            {
                int blocked = 0;
                for (int c = min_c[l]; c <= max_c[l]; c++)
                {
                    char ch = grid[row][c];
                    if (ch == '.')
                        blocked = 1;
                    if (ch >= 'a' && ch <= 'z')
                    {
                        int z = ch - 'a';
                        if (above[l][z])
                            blocked = 1;
                    }
                }
                if (!blocked)
                    can_be_extended = true;
            }

            // Check LEFT
            int col = min_c[l] - 1;
            if (!can_be_extended && col >= 0)
            {
                int blocked = 0;
                for (int r = min_r[l]; r <= max_r[l]; r++)
                {
                    char ch = grid[r][col];
                    if (ch == '.')
                        blocked = 1;
                    if (ch >= 'a' && ch <= 'z')
                    {
                        int z = ch - 'a';
                        if (above[l][z])
                            blocked = 1;
                    }
                }
                if (!blocked)
                    can_be_extended = true;
            }

            // Check RIGHT
            col = max_c[l] + 1;
            if (!can_be_extended && col < C)
            {
                int blocked = 0;
                for (int r = min_r[l]; r <= max_r[l]; r++)
                {
                    char ch = grid[r][col];
                    if (ch == '.')
                        blocked = 1;
                    if (ch >= 'a' && ch <= 'z')
                    {
                        int z = ch - 'a';
                        if (above[l][z])
                            blocked = 1;
                    }
                }
                if (!blocked)
                    can_be_extended = true;
            }

            if (!can_be_extended)
            {
                putchar(paper);
            }
        }

        putchar('\n');
    }

    return 0;
}
