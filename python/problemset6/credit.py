def main():
    card_number = input("Number: ")
    calculate_checksum(card_number)


def calculate_checksum(card):
    card_len = len(card)
    sum = 0

    for i in range(card_len - 1, -1, -1):
        digit = int(card[i])

        if (card_len - i) % 2 == 0:
            digit *= 2

            if digit >= 10:
                sum += int(str(digit)[0]) + int(str(digit)[1])
            else:
                sum += digit
        else:
            sum += digit

    if sum % 10 == 0:
        valid_card(card, card_len)
    else:
        print("INVALID")


def valid_card(card, card_len):
    first_digits = int(card[:2])

    if card_len == 15 and (first_digits == 34 or first_digits == 37):
        print("AMEX")
    elif card_len == 16 and (first_digits >= 51 and first_digits <= 55):
        print("MASTERCARD")
    elif (card_len == 13 or card_len == 16) and card[0] == "4":
        print("VISA")
    else:
        print("INVALID")


main()
