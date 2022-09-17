class Person: # Creates a class name Person
    def __init__(self, name): # Defines a obligatory parameter with 'self' referring to a particular object of the class
        self.name = name # Using the dot operator to set the name attribute to the name parameter again 'self' refers to a particular object of the class

    def talk(self):
        print(f"Hello My name is {self.name}")


john = Person("John Smith") # creates a object within the class Person with the name parameter set to John Smith and the whole thing is stored in a variable named 'john'
john.talk() # here 'self' refers to the object with which it is attached to
mary = Person("Mary Brown")
mary.talk() # here 'self' refers to the object with which it is attached to 