# Project 03 - Pakudex
# University of Florida COP 3502C
# Summer 2022
# Author: Benjamin Uppgard

from pakuri import Pakuri


# Custom exceptions:
class PakudexCapacityError(Exception):
    def __init__(self, value="Pakudex Capacity must be positive"):
        self.value = value


class Pakudex:
    """An index of Pakuri objects"""
    def __init__(self, capacity=20):
        """
        Initialize a new Pakudex instance
        :param capacity: int - The maximum capacity of the Pakudex. Default value is 30
        """

        if capacity < 1:
            raise PakudexCapacityError

        self.capacity = capacity
        self.size = 0
        self.pakuri_list = []
        self.is_full = False

    def get_pakuri(self, species):
        """
        Searches the Pakudex for a given Pakuri. Returns a Pakuri object.
        If the species is not in the Pakudex, returns None.
        :param species: str - the species name of the desired Pakuri
        :return: obj - The desired Pakuri object
        """
        for monster in self.pakuri_list:
            if monster.get_species() == species:
                return monster

    def get_size(self):
        """Returns the number of Pakuri in the Pakudex"""
        return self.size

    def get_capacity(self):
        """Returns the capacity of the Pakudex"""
        return self.capacity

    def get_species_array(self):
        """Returns an array of strings containing all the species
        names of the Pakuri in the Pakudex. If the Pakudex is
        empty, returns None.
        :return: list of strings - a list of the Pakuri species names in the Pakudex
         """
        species_array = []
        for monster in self.pakuri_list:
            species_array.append(Pakuri.get_species(monster))
        if len(species_array) > 0:
            return species_array

    def get_stats(self, species):
        """
        Returns a list of ints of the attack, defense and speed
        statistics for a Pakuri in the Pakudex. If the species is not
        in the Pakudex, returns None.
        :param species: The name of the species stats to be returned.
        :return: a list of ints - The named Pakuri stats - Attack, Defense, Speed
        """
        stat_array = []
        monster = self.get_pakuri(species)
        if monster is not None:
            stat_array.append(monster.get_attack())
            stat_array.append(monster.get_defense())
            stat_array.append(monster.get_speed())
            return stat_array

    def sort_pakuri(self):
        """Sorts the Pakuri in the Pakudex in place by species name"""
        self.pakuri_list.sort()

    def add_pakuri(self, species):
        """
        Checks if a Pakuri with the given species name is in the Pakudex.
        If it is a new Pakuri adds it. If the Pakuri already is in the
        Pakudex, returns False. As Pakuri are added,
        the size attribute of the Pakudex is incremented. If the size attribute
        is greater than or equal to the capacity attribute, sets the
        self_is_full attribute to True.
        :param species: str - The name of the Pakuri to be added
        :return: None
        """
        if self.get_pakuri(species) is None:
            self.pakuri_list.append(Pakuri(species))
            self.size += 1
            if self.get_size() >= self.get_capacity():
                self.is_full = True
            return True
        else:
            return False

    def evolve_species(self, species):
        """
        Attempts to evolve the given species of Pakuri. If successful, returns
        True. If the speices is not in the Pakudex, returns False.
        :param species: str - the species name of the Pakuri to be evolved.
        :return: None
        """
        monster = self.get_pakuri(species)
        if monster is not None:
            monster.evolve()
            return True
        return False







