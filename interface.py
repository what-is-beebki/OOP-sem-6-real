#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import ctypes
libr = ctypes.CDLL('./funny_lib.so')

libr.init_manip.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_double] #x, y, a
libr.add_member_l.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_double, ctypes.c_double, ctypes.c_double] #man, p, x, y, a
libr.add_member_l.restype = ctypes.c_int
libr.add_member_g.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_int] #man, p, x, y, a, g
libr.add_member_g.restype = ctypes.c_int
libr.toggle_grasp.argtypes = [ctypes.c_void_p, ctypes.c_int] #man, n
libr.print_all_members.argtypes = [ctypes.c_void_p] #man
libr.delete_manip.argtypes = [ctypes.c_void_p] #man

class Manip_controller(object):
    def __init__(self):
        self.Man = None
        
    def init_me(self, x, y, a):
        self.Man = libr.init_manip(x, y, a)
    
    def add_link(self):
        print("Добавление звена. Введите параметры.")
        
        try:
            p = int(input("\tНомер звена-родителя: "))
            x = float(input("\tКоордината x: "))
            y = float(input("\tКоордината y: "))
            a = float(input("\tУгол поворота: "))
        except ValueError:
            print("\033[33mмне подсунули неправильное значение\033[0m")
            return        
        err = libr.add_member_l(self.Man, p, x, y, a)
        if err == -1:
            print("\033[33mЭлемент с номером {} не найден\033[0m".format(p))
        if err == -2:
            print("\033[33mЭлемент с номером {} не позволяет присоединить к нему звено\033[0m".format(p))
        return
                
    def add_gripp(self):
        print("Добавление захвата. Введите параметры.")
        
        try:
            p = int(input("\tНомер звена-родителя: "))
            x = float(input("\tКоордината x: "))
            y = float(input("\tКоордината y: "))
            a = float(input("\tУгол поворота: "))
            g = int(input("\tСостояние захвата: "))
        except ValueError:
            print("\033[33mмне подсунули неправильное значение\033[0m")
            return
        
        err = libr.add_member_g(self.Man, p, x, y, a, g)
        if err == -1:
            print("\033[33mЭлемент с номером {} не найден\033[0m".format(p))
        if err == -2:
            print("\033[33mЭлемент с номером {} не позволяет присоединить к нему захват\033[0m".format(p))
        return
                
    def menu(self):
        while True:
            if self.Man is None:
                print("Инициализация. Введите параметры базового звена.")
                
                try:
                    x = float(input("\tКоордината x: "))
                    y = float(input("\tКоордината y: "))
                    a = float(input("\tУгол поворота: "))
                except ValueError:
                    print("\033[33mмне подсунули неправильное значение\033[0m")
                    continue
                
                self.init_me(x, y, a)
                print("Инициализация завершена.")
            else:
                print("Выбор действия.\n\t0. Удалить манипулятор и выйти\n\t1. Удалить манипулятор\n\t2. Добавить звено\n\t3. Добавить захват\n\t4. Распечатать информацию")#приглашение выбрать между удалением, добавлением элемента, распечатыванием
                while True:
                    try:
                        m = int(input("Выбираю "))
                        if m < 0 or m > 4:
                            raise ValueError
                        else:
                            break
                    except ValueError:
                        print("\033[33mмне нужно целое число от 0 до 4\033[0m")
                        continue
                    
                if m == 0: #Удалить манипулятор и выйти
                    libr.delete_manip(self.Man)
                    break
                if m == 1: #Удалить манипулятор
                    libr.delete_manip(self.Man)
                    self.Man = None #нужно ли? или он сам справится?
                                    #нет не справится
                if m == 2: #Добавить звено
                    self.add_link()
                if m == 3: #Добавить захват
                    self.add_gripp()
                if m == 4: #Распечатать информацию
                    libr.print_all_members(self.Man)
                    


if __name__ == '__main__':
    
    try:
        contr = Manip_controller()
        contr.menu()
    except:
        print("\n\033[31mСловил исключение и умер\033[0m")
