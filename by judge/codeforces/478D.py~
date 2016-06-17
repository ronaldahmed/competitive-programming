#import sys
import math
import pdb

MOD = 1000000007
maxn = 100001
memo = {}

def dp(h,r,g):
	if (h,r,g) in memo:
		return memo[(h,r,g)]
	if h <= 0 or r < 0 or g < 0:
		return 0
	if h == 1:
		memo[(h,r,g)] = r + g
		return memo[(h,r,g)]
	memo[(h,r,g)] = dp(h-1,r-h,g) + dp(h-1,r,g-h)
	return memo[(h,r,g)]


if __name__ == "__main__":
	"""
	r,g = sys.stdin.readline().strip('\n').split(' ')
	r = int(r)
	g = int(g)
	"""
	r,g = (9,7)


	height = [int(i*(i+1)/2) for i in range(1,2*maxn)]

	h = 0
	for i,hh in enumerate(height):
		if hh <= r+g:
			h = i+1
		else:
			break

	print(h)

	for i in range(h+1):
		memo[(i,0,0)] = 0	

	res = dp(h,r,g)
	pdb.set_trace()

	#print(memo)
