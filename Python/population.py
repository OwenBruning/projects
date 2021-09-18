import copy
import random
from individual import INDIVIDUAL

class POPULATION:
  def __init__(self,popSize):
    self.p = {}
    self.popSize = popSize
#   for i in range(0,popSize):
#     self.p[i] = INDIVIDUAL(i)
  def Print(self):
    for i in self.p:
      if ( i in self.p ):
        self.p[i].Print()
    print
  def Evaluate(self, pb):
    for i in self.p:
      self.p[i].Start_Evaluation(pb)
    for i in self.p:
      self.p[i].Compute_Fitness(pb)
  def Mutate(self):
    for i in self.p:
      self.p[i].Mutate()
  def ReplaceWith(self,other):
    for i in self.p:
      if ( self.p[i].fitness < other.p[i].fitness ):
        self.p[i] = other.p[i]
  def Initialize(self,popSize):
    for i in range(0,popSize):
      self.p[i] = INDIVIDUAL(i)
  def Fill_From(self,other):
    self.Copy_Best_From(other)
    #self.Print()
    self.Collect_Children_From(other)
    #self.Print()
  def Copy_Best_From(self,other):
    best_index = 0
    for i in range(0, len(other.p)):
      if (other.p[best_index].fitness < other.p[i].fitness):
        best_index = i
    self.p[0] = copy.deepcopy(other.p[best_index])
    return best_index
  def Collect_Children_From(self, other):
    for i in range (1, len(other.p)):
      winner = other.Winner_Of_Tournament_Selection()
      self.p[i] = copy.deepcopy(winner)
      self.p[i].Mutate()
  def Winner_Of_Tournament_Selection(other):
    p1 = random.randint(0, len(other.p)-1)
    p2 = random.randint(0, len(other.p)-1)
    while (p1 == p2):
      p2 = random.randint(0, len(other.p)-1)
    if (other.p[p1].fitness > other.p[p2].fitness):
      return other.p[p1]
    elif (other.p[p1].fitness <= other.p[p2].fitness):
      return other.p[p2]
    else:
      print("Tournament winner is broken.")
