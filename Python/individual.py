import random
import pyrosim
import math
import numpy
from robot import ROBOT

class INDIVIDUAL:
  def __init__(self, i):
    self.ID = i
    #self.genome = numpy.random.random(4) * 2 - 1
    self.genome = (1 + 1) * numpy.random.random_sample((4,8)) - 1
    wts = self.genome
    #self.genome = random.random() * 2 - 1
    #print(self.genome)
    self.fitness = 0
  #def Evaluate(self, pb):
  def Start_Evaluation(self, pb):
    self.sim = pyrosim.Simulator( play_paused = False, eval_time=1500, play_blind = pb ) #false, 1000
    self.robot = ROBOT( self.sim , self.genome )
    self.sim.start()
  def Compute_Fitness(self, pb):
    self.sim.wait_to_finish()
    y = self.sim.get_sensor_data( sensor_id = self.robot.P4 , svi = 1 ) #self.robot.P4
    self.fitness = y[-1]
    del self.sim
  def Mutate(self):
    #geneToMutate = random.randint(0,3)
    #geneToMutate = random.choice(wts)
    #self.genome = random.random() * 2 - 1
    #self.genome[geneToMutate] = random.gauss( self.genome[geneToMutate] , math.fabs(self.genome[geneToMutate]) )
    s = random.randint(0,3)
    m = random.randint(0,7)
    self.genome[s,m] = random.gauss( self.genome[s,m] , math.fabs(self.genome[s,m]) )
    if ( self.genome[s,m] > 1.0 ):
      self.genome[s,m] = 1.0
    if ( self.genome[s,m] < -1.0 ):
      self.genome[s,m] = -1.0
    #self.genome = random.gauss( self.genome , math.fabs(self.genome) )
  def Print(self):
    print('['),
    print(self.ID),
    print(self.fitness),
    print('] '),
