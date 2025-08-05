import sys

class MinHeap:
    def __init__(self):
        self.heap = []
    
    def _parent(self, i):
        return(i - 1) // 2
    def _left(self, i):
        return 2 * i + 1
    def _right(self, i):
        return 2 * i + 2
    def _heapify_up(self, i):
        while i > 0 and self.heap[self._parent(i)] > self.heap[i]:
            self.heap[self._parent(i)], self.heap[i] = self.heap[i], self.heap[self._parent(i)]
            i = self._parent(i)
    def _heapify_down(self, i):
        smallest = i
        l = self._left(i)
        r = self._right(i)
        
        if l < len(self.heap) and self.heap[l] < self.heap[smallest]:
            smallest = l
        if r < len(self.heap) and self.heap[r] < self.heap[smallest]:
            smallest = r
        if smallest != i:
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            self._heapify_down(smallest)
    
    def push(self, val):
        self.heap.append(val)
        self._heapify_up(len(self.heap) - 1)
    def top(self):
        if not self.heap:
            return 0
        return self.heap[0]
    def pop(self):
        if not self.heap:
            return
        self.heap[0], self.heap[-1] = self.heap[-1], self.heap[0]
        self.heap.pop()
        self._heapify_down(0)
    def empty(self):
        return len(self.heap) == 0
    
def main():
    input = sys.stdin.readline

    N = int(input())
    min_heap = MinHeap()

    for _ in range(N):
        x = int(input())

        if x == 0:
            if min_heap.empty():
                print(0)
            else:
                print(min_heap.top())
                min_heap.pop()
        else:
            min_heap.push(x)

main()