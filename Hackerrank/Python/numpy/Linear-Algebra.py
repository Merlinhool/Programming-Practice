import numpy
n = int(input())
mtx = [list(map(float, input().split())) for i in range(n)]
print(numpy.linalg.det(mtx))
