# This file is part of the Neper software package.
# Copyright(C) 2003-2022, Romain Quey.
# See the COPYING file in the top-level directory.

set (test_command -V "mydata(type=vector):file(myvects)" -space ipf -imageformat asy -print test)
include(../../test.cmake)
