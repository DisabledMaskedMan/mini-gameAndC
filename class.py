class human:
    human_num = 0
    _trait1 = 10
    __trait = 9

    def __init__(self,name = "unknown",sex = "unknown",high = 0,weight = 0):
        self.__name = name
        self.__sex = sex
        self.__high = high
        self.__weight = weight

    @classmethod
    def show_num(cls):
        print(cls.human_num)

    def Get(self):
        return self.__sex

    def Set(self,new_sex):
        self.__sex = new_sex

    def Dele(self):
        print("delete OK")
        del self.__sex

    Fun_x = property(fget = Get, fset = Set,fdel = Dele)

human1 = human("zhangsan","man",180,60)
print(human1.Fun_x)
human1.Fun_x = "woman"
print(human1.Fun_x)
del human1.Fun_x
