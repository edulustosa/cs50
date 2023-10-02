import sqlite3

conn = sqlite3.connect("favorites.db")
cursor = conn.cursor()

favorite = input("Favorite: ")

cursor.execute("SELECT COUNT(*) FROM favorites WHERE problem = ?", (favorite,))
results = cursor.fetchall()

for line in results:
    print(line[0])

conn.close()

# import csv
# import sqlite3

# with open("favorites.csv") as file:
#     reader = csv.DictReader(file)
#     counts = {}
#     for line in reader:
#         favorite = line["problem"]
#         if favorite in counts:
#             counts[favorite] += 1
#         else:
#             counts[favorite] = 1

# favorite = input("Favorite: ")
# if favorite in counts:
#     print(f"{favorite}: {counts[favorite]}")

# # for favorite in sorted(counts, key=lambda problem: counts[problem], reverse=True):
# #     print(f"{favorite}: {counts[favorite]}")
