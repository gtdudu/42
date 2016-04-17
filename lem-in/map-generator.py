#!/usr/bin/env python

import sys
import argparse
import random

def get_ant():
	ant = random.randint(0, 200)
	return ant

def make_rooms(r):
	sample = random.sample(range(1, r*4), r*3)
	rooms = sample[:r]
	coord1 = sample[r:r*2]
	coord2 = sample[r*2:r*3]
	start = random.choice(rooms)
	end = random.choice(rooms)
	while start == end:
		end = random.choice(rooms)
	for i in range(r):
		if rooms[i] == start:
			print '##start'
		elif rooms[i] == end:
			print '##end'
			end = rooms[i]
		print rooms[i], coord1[i], coord2[i]
	return {'start':start, 'end':end, 'rooms':rooms}

def make_tubes(start, end, r, rooms, t, solvable):
	i = 0
	while i < r:
		j = 0
		while j < t:
			print "%d%s%d" % (rooms[i],'-',random.choice(rooms))
			j += 1
		i += 1
	if solvable:
		j = 0
		rand = random.randint(1, 9)
		while j < rand:
			connect = random.choice(rooms)
			if connect == start:
				connect = random.choice(rooms)
			print "%d%s%d" % (start,'-',connect)
			start = connect
			j += 1
		print "%d%s%d" % (connect,'-',end)

if __name__ == "__main__":
	parser = argparse.ArgumentParser()

	parser.add_argument("-a", "--ants", type=int, default=get_ant(), help="Number of ants. Must be >= 0.")
	parser.add_argument("-r", "--rooms", type=int, default=10, help="Number of rooms. Must be >= 0.")
	parser.add_argument("-s", "--solvable", action="store_true", default=False, help="Forces generation of a solvable puzzle. Overrides -u.")
	args = parser.parse_args()

	if not args.solvable:
		solv = random.choice([True, False])
	elif args.solvable:
		solv = True

	if args.rooms < 0:
		print "Number of rooms can't be negative"
	elif args.rooms > 999:
		print "This will fuck it up for sure"
	if args.ants < 0:
		print "Number of ants can't be negative"
	
	random.seed()
	if args.rooms > 0 and args.ants > 0 and args.rooms <= 999:
		a = args.ants
		print a
		print "#Generating rooms"
		r = args.rooms
		if r < 2:
			print "#This map is unsolvable"
		t = 1;
		result = make_rooms(r)
		print "#Generating tubes"
		make_tubes(result['start'], result['end'], r, result['rooms'], t, solvable=solv) 
