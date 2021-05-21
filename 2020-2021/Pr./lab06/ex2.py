import tkinter
import random
WIDTH = 1920
HEIGHT = 1080
BG_COLOR = 'white'
M_RADIUS = 30
M_COLOR = 'green'
INIT_DX = 3 
INIT_DY = 3
S_BALL = 10
MAX_RADIUS = 40
MIN_RADIUS = 20
BAD_COLOR = 'red'
COLORS = ['blue', 'gold', 'green', 'black', BAD_COLOR]
NUM_OF_BALLS = 4

class Balls():
    def __init__(self, x, y, r, color, dx=0, dy=0):
        self.x = x
        self.y = y
        self.r = r
        self.color = color
        self.dx = dx
        self.dy = dy

    def draw(self):
        canvas.create_oval(self.x-self.r, self.y-self.r, 
                           self.x+self.r, self.y+self.r,
                           fill=self.color, outline=BG_COLOR
                           if self.color != BAD_COLOR else 'black')

    def hide(self):
        canvas.create_oval(self.x-self.r, self.y-self.r, 
                           self.x+self.r, self.y+self.r,
                           fill=BG_COLOR, outline=BG_COLOR)

    def is_collision(self,ball):
        a = abs(self.x+self.dx-ball.x)
        b = abs(self.y+self.dy-ball.y)
        return (a*a + b*b)**0.5 <= self.r + ball.r

    def move(self):
        if (self.x+self.r+self.dx>=WIDTH) or (self.x-self.r+self.dx<=0):
            self.dx = -self.dx
        if (self.y+self.r+self.dy>=HEIGHT) or (self.y-self.r+self.dy<=0):
            self.dy = -self.dy
        for ball in balls:
            if self.is_collision(ball):
                if ball.color != BAD_COLOR:
                    ball.hide()
                    balls.remove(ball)
                    self.dx = -self.dx
                    self.dy = -self.dy
                else:
                    self.dx = self.dy = 0
        self.hide()
        self.x += self.dx
        self.y += self.dy
        self.draw()

def mouse_click(event):
    global main_ball
    if event.num == 1:
        if 'main_ball' not in globals():
            main_ball = Balls(event.x, event.y, M_RADIUS, M_COLOR, INIT_DX, INIT_DY)
            main_ball.draw()
        else:
            if main_ball.dy*main_ball.dx>0:
                main_ball.dy = -main_ball.dy
            else:
                main_ball.dx = -main_ball.dx
    elif event.num == 3:
        if main_ball.dy*main_ball.dx>0:
            main_ball.dx = -main_ball.dx
        else:
            main_ball.dy = -main_ball.dy

def create_list_of_balls(number):
    lst = []
    while len(lst)< number:
        next_ball = Balls(random.choice(range(MAX_RADIUS, WIDTH-MAX_RADIUS)),
                          random.choice(range(MIN_RADIUS, HEIGHT-MIN_RADIUS)),
                          random.choice(range(MIN_RADIUS, MAX_RADIUS)),
                          random.choice(COLORS))
        is_collision = False
        for ball in lst:
            if next_ball.is_collision(ball):
                is_collision = True
                break
        if not is_collision:
            lst.append(next_ball)
            next_ball.draw()
    return lst

def count_bad_balls(list_of_balls):
    result = 0
    for ball in list_of_balls:
        if ball.color == BAD_COLOR:
            result += 1
    return result

def main():
    if 'main_ball' in globals():
        main_ball.move()
        if len(balls)-num_of_bad_balls == 0:
            canvas.create_text(WIDTH/2, HEIGHT/2, text = 'You won!',
                               font = 'Arial 20', fill = 'green')
            main.ball.dx = main.ball.dy = 0 
        elif main_ball.dx*main_ball.dy == 0:
            canvas.create_text(WIDTH/2, HEIGHT/2, text = 'Loose!',
                               font = 'Arial 20', fill = 'red')
    root.after(S_BALL,main)


root = tkinter.Tk()
root.title('Magic balls')
canvas = tkinter.Canvas(root,width = WIDTH, height = HEIGHT, bg = BG_COLOR)
canvas.pack()
canvas.bind('<Button-1>',mouse_click)
canvas.bind('<Button-3>',mouse_click, '+')
balls = create_list_of_balls(NUM_OF_BALLS)
num_of_bad_balls = count_bad_balls(balls)
main()

root.mainloop()