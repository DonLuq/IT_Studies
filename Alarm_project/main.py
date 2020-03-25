import tkinter as Think
import time


class Board(object):
    def __init__(self, width, height):
        self.window = Think.Tk()
        self.window.title("Alarm Clock!")
        self.window.geometry(str(width)+'x'+ str(height))
        self.window.configure(bg = '#3E4149')
        self.button = Think.Button(self.window, text="SET ALARM", width=10, height=30, highlightbackground='#3E4149', activebackground='#4452cc', activeforeground='#aaffaa')
        self.button.pack()
        # self.zegar = Clock()


    def run(self):
        self.window.mainloop()


# class Clock():
#     def __init__(self):
#         # self.root = Think.Tk()
#         self.label = Think.Label(text="", font=('Helvetica', 48), fg='red')
#         self.label.pack()
#         self.update_clock()
#         self.root.mainloop()
#
#     def update_clock(self):
#         now = time.strftime("%H:%M:%S")
#         self.label.configure(text=now)
#         self.root.after(1000, self.update_clock)

# OBJECT = Think.Tk()
GUI = Board(600, 400)
GUI.run()
# OBJECT.mainloop()
