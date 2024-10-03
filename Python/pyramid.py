#!/usr/bin/env python3
import sys

arg1: int = sys.argv[1]

def pyramid(layer: int) -> str:
    """
    Creates pyramid.
    
    Args:
        layer (int): number of layers

    Returns:
        str: outputs ascii art pyramid
    """
    for i in range(1, int(layer)+1):
        for j in range(1, i+1):
            print("*", end='')
        print("\n", end='')

pyramid(arg1)
