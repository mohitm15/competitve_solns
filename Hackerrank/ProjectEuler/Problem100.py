#By Mohit Maroliya

import eulerlib

def compute():
	x0 = 3
	y0 = 1
	
	x = x0
	y = y0  
	while True:
		sqrt = eulerlib.sqrt(y**2 * 8 + 1)
		if sqrt % 2 == 1:  # Is odd
			blue = (sqrt + 1) // 2 + y
			if blue + y > 10**12:
				return str(blue)
		
		nextx = x * x0 + y * y0 * 8
		nexty = x * y0 + y * x0
		x = nextx
		y = nexty


if __name__ == "__main__":
	print(compute())
