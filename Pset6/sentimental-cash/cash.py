from cs50 import get_float


def main():

    while True:
        change = get_float("Change: ")
        if change > 0:
            break

    quarters = calculate_quarters(change)
    change = round(change - (quarters * 0.25), 2)

    dimes = calculate_dimes(change)
    change = round(change - (dimes * 0.10), 2)

    nickles = calculate_nickles(change)
    change = round(change - (nickles * 0.05), 2)

    pennies = calculate_pennies(change)
    change = round(change - (pennies * 0.01), 2)

    amount = quarters + dimes + nickles + pennies
    print(amount)


def calculate_quarters(coins):
    return coins // .25


def calculate_dimes(coins):
    return coins // .10


def calculate_nickles(coins):
    return coins // .05


def calculate_pennies(coins):
    return coins // .01


main()
