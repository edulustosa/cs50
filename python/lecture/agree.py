s = input("Do you agree? ")
agreed = ["y", "yes"]
not_agreed = ["n", "no"]

s = s.lower()
if s in agreed:
    print("Agreed")
elif s in not_agreed:
    print("Not agreed")
