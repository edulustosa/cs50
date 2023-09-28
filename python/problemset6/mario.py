def main():
    height = get_height()

    for i in range(1, height + 1):
        print(" " * (height - i), end="")

        print("#" * i, end="")

        print("  ", end="")

        print("#" * i)


def get_height():
    while True:
        try:
            height = int(input("Height: "))

            if 1 <= height <= 8:
                return height
            else:
                print("Height must be between 1 and 8")
        except ValueError:
            print("Not an integer")


main()
