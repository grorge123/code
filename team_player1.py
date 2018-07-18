from AI.base import *
from pygame.math import Vector2 as Vec

import random
class TeamAI( BaseAI ):
	def __init__( self , helper ):
		self.helper = helper
		self.skill = []
		self.flag = 0

	def decide( self ):
		helper = self.helper
		hpos = helper.getMyHeadPos()
		wb_radius = helper.getWhiteballRadius()
		dash_distance = helper.dash_time*helper.dash_speed
		if not helper.checkMeInGrav():
			self.flag = 0
			if helper.getOtherBulletNumInRange(hpos, 5 * wb_radius) > 0:
				return AI_MoveWayChange
			if helper.bodyOnRoute() or helper.headOnRoute():
				body = helper.bodyOnRoute() + helper.headOnRoute()
				l = len(body)
				for i in range(l):
					if (hpos[1]-body[i][1])**2+(hpos[0]-body[i][0])**2 > dash_distance**2:
						return AI_NothingToDo
					else:
						return AI_MoveWayChange
		else :
			mygrav = helper.getMyGrav()
			if not helper.checkMeCircling() and not self.flag:
				self.flag = 1
				return AI_MoveWayChange
			elif helper.checkMeCircling():
				return AI_MoveWayChange
			#if helper.getOtherBulletNumInRange(hpos, 5 * wb_radius) > 0:
			#	return AI_MoveWayChange
			#if helper.checkMeCircling() and helper.canGetBySpin() == 0:
			#	return AI_MoveWayChange
			#if not helper.checkMeCircling() and helper.canGetBySpin() > 0:
			#	return AI_MoveWayChange
		return AI_NothingToDo
