import os
import sys

# compute the longest sub sequence of two strings

a = 'mitcmu'
b = 'mtacnu'
mindst = [100]
# recursiving method to compute the longest sub-sequence of two strings
def lcs(i, j):
    if (i == -1 or j == -1):
        return 0
    if (a[i] == b[j]):
        return lcs(i - 1, j - 1) + 1
    else:
        return  max(lcs(i - 1, j), lcs(i, j - 1))


# recursing memthod to compute the laiwensitan editing distance
def lwstBT(i, j, edlist):
    if (i == len(a) or j == len(b) ):
        if i < len(a):
            edlist = edlist + (len(a) - i)
        if j < len(b):
            edlist = edlist + (len(b) - j)
        if edlist < mindst[0] :
            mindst[0] = edlist
        return
    if a[i] == b[j]: # a[i] and a[j] match, then move i and j to next character
        lwstBT(i + 1, j + 1, edlist)
    else :
        lwstBT(i + 1, j, edlist + 1) # delete a[i] or add a[i] before b[j], but don't forget plus one to edlist
        lwstBT(i, j + 1, edlist + 1) # delete b[j] or and b[j] before a[i], but don't forget plus one to edlist
        lwstBT(i + 1, j + 1, edlist + 1) # charge a[i] to b[j] or change b[j] to a[i], don't forget plus one to edlist

# dynamic plan method to compute the laiwensitan distance 

d = [[0, 0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0, 0]]

def lwstDP():
    for i in range(len(a)):
        d[i][0] = i
    for j in range(len(b)):
        d[0][j] = j

    for i in range(1, len(a)):
        for j in range(1, len(b)):
            if (a[i] != b[j]):
                d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + 1)
            if (a[i] == b[j]):
                d[i][j] = d[i - 1][j - 1]

    return d[len(a) - 1][len(b) - 1]

if __name__ == '__main__':
    print (lcs(len(a) - 1, len(b) -1))
    lwstBT(0, 0, 0)
    print mindst
    print lwstDP()
