# This file is part of the Neper software package.
# Copyright(C) 2003-2022, Romain Quey.
# See the COPYING file in the top-level directory.

set (test_command -V n2-id1-per.tess -showcell 0 -showcrystal 1 -datacrystalcol id -imageformat pov -print test)
include(../../test.cmake)
