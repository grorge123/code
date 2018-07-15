from AI.base import *
from pygame.math import Vector2 as Vec

import random
def Abs(a)
    if(a>0):
        return a
    else:
        return a*-1
class TeamAI( BaseAI ):
    def __init__( self , helper ):
        self.helper = helper
        self.skill = []

    def decide( self ):
        helper = self.helper
        allbull = helper.getAllPlayerBullet()
        now = helper.getMyHeadPos()
        if helper.getMyGrav() == None:
            if helper.getDashPos() in allbull:
                return AI_NothingToDo
            else:
                return AI_MoveWayChange
        else:
            nodo = True
            for i in allbull:
                if not (Abs(now[0]-i[0])>2 and Abs(now[1]-i[1])>2):
                    nodo = False
            return AI_NothingToDo if nodo else AI_MoveWayChange
