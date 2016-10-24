class Student:

    # Set init for each section of the student's profile
    def __init__(self, name, student_id, gpa, final, full_or_part):
        self.__name = name
        self.__student_id = student_id
        self.__gpa = gpa
        self.__final = final
        self.__full_or_part = full_or_part

    # Define set functions
    def set_student_id(self, student_id):
        self.__student_id = student_id

    def set_gpa(self, gpa):
        self.__gpa = gpa

    def set_final(self, final):
        self.__final = final

    def set_full_or_part(self, full_or_part):
        self.__full_or_part = full_or_part

    # Define get functions
    def get_student_id(self):
        return self.__student_id

    def get_gpa(self):
        return self.__gpa

    def get_final(self):
        return self.__final

    def get_full_or_part(self):
        return self.__full_or_part

    def get_name(self):
        return self.__name

    # Store data in a string
    def __str__(self):
        return "Name: " + self.__name + \
               "\nAlphanech0ID: " + self.__student_id + \
               "\nGPA: " + self.__gpa + \
               "\nFinal Grade: " + self.__final + \
               "\nFull or Part Time: " + self.__full_or_part
