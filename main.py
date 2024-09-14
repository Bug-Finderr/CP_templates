import sys
import threading
import bisect
import heapq
import math
from collections import defaultdict, deque, Counter
from itertools import combinations, permutations, accumulate
from functools import lru_cache, reduce

# Macros
def input(): return sys.stdin.readline().rstrip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))

# Aliases and Constants
INF = float('inf')
MOD = 10**9 + 7
PI = math.pi



def solve():
    t: int = 1
    
    # t = INT()       # Uncomment the following line if there are multiple test cases
    for _ in range(t):
        # Example input processing:
        # n = INT()
        # arr = LIST()
        # s = STR()

        # Your code here
        pass



def main():
    threading.Thread(target=solve).start()

if __name__ == "__main__":
    sys.setrecursionlimit(1 << 25)
    main()
