# Project 03 - Pakudex
# University of Florida COP 3502C
# Summer 2022
# Author: Benjamin Uppgard

from pakudex import Pakudex, PakudexCapacityError


# Custom exception:
class MenuError(Exception):
    def __init__(self, value="Selection is not a Menu Option"):
        self.value = value


def print_menu():
    """Prints the program menu"""
    print("Pakudex Main Menu\n"
          "-----------------\n"
          "1. List Pakuri\n"
          "2. Show Pakuri\n"
          "3. Add Pakuri\n"
          "4. Evolve Pakuri\n"
          "5. Sort Pakuri\n"
          "6. Exit\n"
          "\n")


if __name__ == '__main__':

    # Display the welcome message:
    print("Welcome to Pakudex: Tracker Extraordinaire!")

    # Initialize the Pakudex
    user_dex = None
    while user_dex is None:
        try:
            pakudex_cap = int(input("Enter max capacity of the Pakudex: "))
            user_dex = Pakudex(pakudex_cap)
            print(f"The Pakudex can hold {pakudex_cap} species of Pakuri.\n")
        except (ValueError, PakudexCapacityError):
            print("Please enter a valid size.")

    # Main program loop:
    selection = None
    while selection != 6:

        print_menu()

        # Prompt user for desired action:
        try:
            selection = int(input("What would you like to do? "))
            if selection < 1 or selection > 6:
                raise MenuError
        except (ValueError, MenuError):
            print("Unrecognized menu selection!\n")
            continue

        # Selection 1: List Pakuri
        if selection == 1:
            pakuri_list = user_dex.get_species_array()
            if pakuri_list is None:
                print("No Pakuri in Pakudex yet!\n")
                continue
            print("Pakuri In Pakudex:")
            for i, pakuri_name in enumerate(pakuri_list):
                print(f"{i + 1}. {pakuri_name}")
            print()

        # Selection 2: Show Pakuri Stats
        elif selection == 2:
            target_name = input("Enter the name of the species to display: ")
            stats = user_dex.get_stats(target_name)
            if stats is None:
                print("Error: No such Pakuri!\n")
            else:
                print(f"Species: {target_name}\n"
                      f"Attack: {stats[0]}\n"
                      f"Defense: {stats[1]}\n"
                      f"Speed: {stats[2]}\n")

        # Selection 3: Add Pakuri to Pakudex
        elif selection == 3:
            if user_dex.is_full:
                print("Error: Pakudex is full!\n")
                continue
            new_name = input("Enter the name of the species to add: ")
            if user_dex.add_pakuri(new_name):
                print(f"Pakuri species {new_name} successfully added!\n")
            else:
                print("Error: Pakudex already contains this species!\n")

        # Selection 4: Evolve a Pakuri
        elif selection == 4:
            evolve_name = input("Enter the name of the species to evolve: ")
            if user_dex.evolve_species(evolve_name):
                print(f"{evolve_name} has evolved!")
            else:
                print("Error: No such Pakuri!\n")

        # Selection 5: Sort the Pakuri in the Pakudex
        elif selection == 5:
            user_dex.sort_pakuri()
            print("Pakuri have been sorted!\n")

        # Selection 6: Quit
        elif selection == 6:
            print("Thanks for using Pakudex! Bye!")
            break










