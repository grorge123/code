from AI.base import *
from pygame.math import Vector2 as Vec

import random
class TeamAI( BaseAI ):
	def __init__( self , helper ):
		self.helper = helper
		self.skill = []
		self.flag = 0
		self.time = 0
	def mr(self,pos,R):
		Pos = Vec(pos)
		L = 800 - R
		if Pos.x < R:
			Pos.x = -Pos.x+2*R
		if Pos.y < R:
			Pos.y = -Pos.y+2*R
		if Pos.x > L:
			Pos.x = 2 * L - Pos.x
		if Pos.y > L:
			Pos.y = 2 * L - Pos.y
		return Pos

	def decide( self ):
		self.time += 1
		self.time %= 3
		et = 0
		helper = self.helper
		hpos = helper.getMyHeadPos()
		wb_radius = helper.getWhiteballRadius()
		b = helper.getAllPlayerBullet()
		r_h = helper.head_radius
		dash_distance = helper.dash_time*helper.dash_speed
		if not helper.checkMeInGrav():
			self.flag = 0
			for x in b:
				if (self.mr(Vec(x[1])+Vec(x[2])*x[4],x[3]) - Vec(hpos)).length() < x[3] + r_h + 2:
					et = 1
			if helper.bodyOnRoute() or helper.headOnRoute():
				body = helper.bodyOnRoute() + helper.headOnRoute()
				l = len(body)
				for i in range(l):
					if (hpos[1]-body[i][1])**2+(hpos[0]-body[i][0])**2 > (8*helper.head_radius)**2:
						return AI_NothingToDo
					else:
						return AI_MoveWayChange
			if et:
				return AI_MoveWayChange
		else :
			mygrav = helper.getMyGrav()
			if not helper.checkMeCircling() and not self.flag:
				self.flag = 1
				return AI_MoveWayChange
			elif helper.checkMeCircling():
				return AI_MoveWayChange
			for body in helper.bodyOnRoute():
				if (Vec(hpos)-Vec(body)).length_squared()<=(3*helper.head_radius)**2 and self.time==0:
					return AI_MoveWayChange
			# if helper.getOtherBulletNumInRange(hpos, 5 * wb_radius) > 0:
			# 	return AI_MoveWayChange
			# if helper.checkMeCircling() and helper.canGetBySpin() == 0:
			# 	return AI_MoveWayChange
			# if not helper.checkMeCircling() and helper.canGetBySpin() > 0:
			# 	return AI_MoveWayChange
		return AI_NothingToDo
