#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import ctypes
libr = ctypes.CDLL('./funny_lib.so')

libr.init_manip.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_double] #x, y, a
libr.add_member_l.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_double, ctypes.c_double, ctypes.c_double] #man, p, x, y, a
libr.add_member_g.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_int] #man, p, x, y, a, g
libr.toggle_grasp.argtypes = [ctypes.c_void_p, ctypes.c_int] #man, n
libr.print_all_members.argtypes = [ctypes.c_void_p] #man
libr.delete_manip.argtypes = [ctypes.c_void_p] #man

Arm = libr.init_manip(1.5, 0.9, 0)

libr.add_member_l(Arm, 1, 5, 0, 0)
libr.add_member_l(Arm, 2, 4, 8, -0.7)
libr.add_member_l(Arm, 3, 3, 0, 0.3)
libr.add_member_g(Arm, 4, 0.5, 0.5, 0.55, 1)

libr.print_all_members(Arm)

libr.toggle_grasp(Arm, 5)

libr.print_all_members(Arm)

libr.delete_manip(Arm)
