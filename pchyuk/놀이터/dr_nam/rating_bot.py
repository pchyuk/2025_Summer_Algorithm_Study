import requests
# import: pip install requests

usernames = [
    "pch6590",
    "lune_am",
    "jhpark1440",
    "quivy",
    "madongseok_knightage",
    "greatyb0925",
    "hwoo1723",
    "blooberry"
]
notfound = []
url = "https://solved.ac/api/v3/search/user"

def tier_name(tier_num: int) -> str:
    if tier_num == 0:
        return "Unrated"
    groups = ["Bronze", "Silver", "Gold", "Platinum", "Diamond", "Ruby"]
    if 1 <= tier_num <= 30:
        group_idx = (tier_num - 1) // 5
        roman_level = 5 - ((tier_num - 1) % 5)
        romans = {1:"I", 2:"II", 3:"III", 4:"IV", 5:"V"}
        return f"{groups[group_idx]} {romans[roman_level]}"
    if tier_num == 31:
        return "Master"
    return f"Tier {tier_num}"

print(f"{'handle':^15} | {'rating':^7} | {'tier':^7}")
print("-"*40)

for name in usernames:  
    params = {"query": name}
    res = requests.get(url, params=params)
    data = res.json()

    if data["count"] > 0:
        user = data["items"][0]
        tier = tier_name(user.get("tier", 0))
        print(f"{user['handle']:^15} | {user['rating']:^7} | {tier:<^7}")
    else:
        notfound.append(name)

if notfound:
    print(f"users: {', '.join(notfound)}     can't be found")