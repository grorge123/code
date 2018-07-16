from AI.base import *
from pygame.math import Vector2 as Vec

import random

class TeamAI( BaseAI ):
    def __init__( self , helper ):
        self.helper = helper
        self.skill = []

    def decide( self ):
        helper = self.helper
        hPos = helper.getMyHeadPos()
        wb_radius = helper.getWhiteballRadius()
        if helper.getOtherBulletNumInRange(hPos, 3 * wb_radius) > 0:
            return AI_MoveWayChange
        if not helper.checkMeInGrav():
            if helper.bodyOnRoute() or helper.headOnRoute():
                return AI_MoveWayChange
        else :
            if helper.checkMeCircling():
                return AI_MoveWayChange
        return AI_NothingToDo
