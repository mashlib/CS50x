from cs50 import get_string


def main():
    text = get_string("Text: ")
    letters = 0
    words = 1
    sentences = 0

    for c in range(len(text)):
        if text[c].isalpha():
            letters += 1

        if text[c] == " ":
            words += 1

        if text[c] == '.' or text[c] == '!' or text[c] == '?':
            sentences += 1

    l = (letters / words) * 100
    s = (sentences / words) * 100
    index = 0.0588 * l - 0.296 * s - 15.8
    index = round(index)

    if index < 1:
        print("Before Grade 1")

    elif index > 16:
        print("Grade 16+")

    else:
        print(f"Grade {index}")


main()
