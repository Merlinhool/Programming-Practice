#import numpy
#
#def inputList():
    #return [int(i) for i in input().split()]
#
#[n,m] = inputList()
#mtx = inputList()
#for i in range(n-1):
    #mtx = numpy.vstack((mtx, inputList()))
#
#print(numpy.transpose(mtx))
#print(mtx.flatten())

#The Editorial solution:
import numpy
n, m = map(int, input().split())
arr = numpy.array([list(map(int, input().split())) for i in range(n)])
print(numpy.transpose(arr))
print(arr.flatten())
