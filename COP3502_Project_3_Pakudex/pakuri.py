# Project 03 - Pakudex
# University of Florida COP 3502C
# Summer 2022
# Author: Benjamin Uppgard

class Pakuri:
    """A class to represent a Pakuri."""
    def __init__(self, species):
        """
        Constructs a new Pakuri class instance.
        :param species: str - The species name of the new Pakuri
        """
        self.species = species
        self.attack = (len(species) * 7) + 9
        self.defense = (len(species) * 5) + 17
        self.speed = (len(species) * 6) + 13

    # Overload operators
    def __repr__(self):
        return f"{self.species}-A:{self.attack}-D:{self.defense}-S{self.speed}"

    def __str__(self):
        return f"{self.species}, AT:{self.attack}, DF:{self.defense}, SP{self.speed}"

    def __lt__(self, other):
        return self.species < other.species

    def __le__(self, other):
        return self.species <= other.species

    def __eq__(self, other):
        return self.species == other.species

    def __gt__(self, other):
        return self.species > other.species

    def __ge__(self, other):
        return self.species >= other.species

    def get_species(self):
        """Returns a str - the Pakuri species name."""
        return self.species

    def get_attack(self):
        """Returns an int - the Pakuri attack stat."""
        return self.attack

    def get_defense(self):
        """Returns an int - the Pakuri defense stat."""
        return self.defense

    def get_speed(self):
        """Returns an int - the Pakuri speed stat. """
        return self.speed

    def set_attack(self, new_attack):
        """
        Updates the Pakuri object attack stat.
        :param new_attack: int - The new attack stat value.
        :return: None
        """
        self.attack = new_attack

    def evolve(self):
        """Evolves the referenced Pakuri.
        Doubles attack,
        quadruples defense,
        triples speed."""
        self.attack = self.attack * 2
        self.defense = self.defense * 4
        self.speed = self.speed * 3


