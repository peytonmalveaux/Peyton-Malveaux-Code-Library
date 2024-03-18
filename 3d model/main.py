import pygame as pg
from object3d import *
from camera import *
from projection import *

#render the screen
class ScreenRender:
    def __init__(self) :
        pg.init
        self.RES = self.WIDTH, self.HEIGHT = 1600, 900
        self.H_HEIGHT, self.H_WIDTH = self.WIDTH // 2, self.HEIGHT // 2
        self.fps = 60
        self.screen = pg.display.set_mode(self.RES)
        self.clock = pg.time.Clock()
        self.create_object()


    def create_object(self):
        self.camera = Camera(self, [0.5, 1, -4])
        self.projection = Projection(self)
        self.object = Object3d(self)
        self.object.translate([0.2, 0.4, 0.2])
        self.object.rotate_y(math.pi/6)


    def draw(self):
        self.screen.fill(pg.Color('darkslategray'))
        self.object.draw()
         

#color the screen                             
    def color(self):
        self.screen.fill(pg.Color('darkslategray'))


 

    def run(self):
        while True:
            self.color()
            [exit() for i in pg.event.get() if i.type == pg.QUIT]
            pg.display.set_caption(str(self.clock.get_fps()))
            pg.display.flip()#idk
            self.clock.tick(self.fps)

if __name__ == '__main__':
    app = ScreenRender()
    app.run()

