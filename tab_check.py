#!/usr/bin/python

import sys

def help():
    print "usage:"
    print "\t" + sys.argv[0] + " [file name]"
    print
    print "author: Mustafa CAMURLI"
    print "e-mail: mustafacamurli@gmail.com"

if __name__ == '__main__':
    
    f_handle = None
    stream   = None
    row      = 1
    col      = 1

    if len(sys.argv) < 2:
        help()
        exit(0)
        
    try:
        f_handle = open(sys.argv[1])
        stream = f_handle.read()
        f_handle.close()
        
        for c in range(len(stream)):
            if '\t' == stream[c]:
                print "tab character is detected at row: " + str(row) + ", col: " + str(col)
                col += 1
            if '\n' == stream[c]:
                row += 1
                col  = 1
            else:
                col += 1

                

    except IOError as err:
        print "I/O error({0}): {1}".format(err.errno, err.strerror)
    except:
        print "Unexpected error:", sys.exc_info()[0]
        exit(0)
    exit(0)
