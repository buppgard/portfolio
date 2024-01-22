# UF Online COP3502C
# Project 01 "Blackjack"
# June 2022
# Author: Benjamin Uppgard

# Import library for psudo-random number generation
import p1_random as p1
rand = p1.P1Random()

# Game Variables
game_state = 1
player_hand = 0
dealer_hand = 0

# Statistics Variables
total_games = 0
wins = 0
losses = 0
ties = 0

# Print a menu return the user's selection
def user_input():
    print("1. Get another card\n"
          "2. Hold hand\n"
          "3. Print statistics\n"
          "4. Exit\n"
          "\n"
          "Choose an option: ", end="")
    selection = input()
    print()
    return(int(selection))

# Deal a random card to the user and return the card's point value
def deal_a_card():
    card_value = rand.next_int(13) + 1
    if card_value == 1:
        card = "ACE"
    elif card_value == 11:
        card = "JACK"
        card_value = 10
    elif card_value == 12:
        card = "QUEEN"
        card_value = 10
    elif card_value == 13:
        card = "KING"
        card_value = 10
    else:
        card = str(card_value)
    print(f"Your card is a {card}!")
    return(card_value)

# Check to see if the last turn resulted in a win. Record the results and
# return 1 if the turn resulted in a win, loss or tie (i.e. the game is over).
def check_for_win():

    # Golbal vairables passed into the function
    global total_games
    global wins
    global losses
    global ties
    global dealer_hand
    global player_hand
    global game_state

    # Win/loss/tie conditions
    if dealer_hand > 0 or player_hand >= 21:
        if player_hand == 21:
            print("BLACKJACK! You win!\n")
            wins += 1
        elif player_hand > 21:
            print(f"You exceeded 21! You lose.\n")
            losses += 1
        elif dealer_hand > 21 or player_hand > dealer_hand:
            print("You win!\n")
            wins += 1
        elif player_hand == dealer_hand:
            print("It's a tie! No one wins!\n")
            ties += 1
        elif dealer_hand > player_hand:
            print("Dealer wins!\n")
            losses += 1

        # If any win/loss/tie conditions are met, the results
        # are logged, a new game is started and the function
        # returns a 1.
        total_games += 1
        dealer_hand = 0
        player_hand = 0
        game_state = 1
        print(f"START GAME #{total_games + 1}\n")
        return 1

# The start of the game
print(f"START GAME #{total_games + 1}\n")

# Loop until the user quits
while game_state != 4:

    # If the user selects 1, they are delt a card.
    # After each card is delt, win conditions are checked.
    if game_state == 1:
        next_card = deal_a_card()
        player_hand = player_hand + next_card
        print(f"Your hand is: {player_hand}\n")
        result = check_for_win()
        if result == 1:
            continue

    # If the user selects 2, the dealer's cards are delt.
    # After, win conditions are checked.
    elif game_state == 2:
        dealer_hand = rand.next_int(11) + 16
        print(f"Dealer's hand: {dealer_hand}\n"
              f"Your hand is: {player_hand}\n")
        result = check_for_win()
        if result == 1:
            continue

    # If the user selects 3, game statistics are displayed.
    elif game_state == 3:
        print(f"Number of Player wins: {wins}\n"
              f"Number of Dealer wins: {losses}\n"
              f"Number of tie games: {ties}\n"
              f"Total # of games played is: {total_games}\n"
              f"Percentage of Player wins: {round((wins / total_games) * 100, 1)}%\n")

    # Any invalid inputs generate an error.
    else:
        print("Invalid input!\n"
              "Please enter an integer value between 1 and 4.\n")

    # After each round, the user is asked for input.
    game_state = user_input()

