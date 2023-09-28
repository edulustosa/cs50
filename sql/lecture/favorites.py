import csv

with open("favorites.csv") as file:
    reader = csv.DictReader(file)
    counts = {}
    for line in reader:
        favorite = line["problem"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

favorite = input("Favorite: ")
if favorite in counts:
    print(f"{favorite}: {counts[favorite]}")

# for favorite in sorted(counts, key=lambda problem: counts[problem], reverse=True):
#     print(f"{favorite}: {counts[favorite]}")
