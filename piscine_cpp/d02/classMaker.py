#!/usr/bin/python

'''

#ifndef K_HPP

# define K_HPP

classK {



public:

K(void);

K(K const&);

K &operator=(K const&);

~K(void);

};





#include "K.hpp"



K::K(void) {

;

}



K::~K(void) {

;

}



h = "Class\tK {\n\npublic:\n\tK(void);\n\t~K(void);\n};\n"



c = "#include \"K.hpp\"\n\nK::K(void) {\n\t;\n}\n\nK::~K(void) {\n\t;\n}\n

'''

import sys

import os



h = '#ifndef LLL_HPP\n# define LLL_HPP\n\nclass\tK {\n\npublic:\n\tK(void);\n\tK(K const&);\n\tK &\toperator=(K const&);\n\t~K(void);\n};\n\n#endif\n'



c = '#include "K.hpp"\n\nK::K(void) {\n\t;\n}\n\nK::K(K const& inst) {\n\t;\n}\n\nK &\tK::operator=(K const& inst) {\n\treturn (*this);\n}\n\nK::~K(void) {\n\t;\n}\n'



if len(sys.argv) != 2:

    exit

if sys.argv[1][0] not in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':

    exit

if ' ' in sys.argv[1][0]:

    exit



cpp = "%s.cpp" % sys.argv[1]

if os.path.exists(cpp):

    print cpp + ' exists'

    exit

hpp = "%s.hpp" % sys.argv[1]

if os.path.exists(hpp):

    print hpp + ' exists'

    exit



open(cpp, "w+").write(c.replace("K", sys.argv[1]))

open(hpp, "w+").write(h.replace("K", sys.argv[1]).replace("LLL", sys.argv[1].upper()))



print '%s and %s created' % (cpp, hpp)
