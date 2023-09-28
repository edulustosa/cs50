def main():
    letters = 0
    words = 0
    senteces = 0

    text = input("Text: ")

    for c in text:
        if c.isalpha():
            letters += 1

        if c == " ":
            words += 1

        if c == "." or c == "!" or c == "?":
            senteces += 1
    words += 1

    l = letters / words * 100
    s = senteces / words * 100

    index = 0.0588 * l - 0.296 * s - 15.8
    index = round(index)

    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


main()
