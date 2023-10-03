from tkinter import *

k = 25
R = 5

t = -500
p = -300

outp = open('output.txt')

x1 = x2 = x3 = y1 = y2 = y3 = x0 = y0 = 0

m = outp.read()
r = [float(x) for x in m.split()]

x1 = r[0]
y1 = r[1]
x2 = r[2]
y2 = r[3]
x3 = r[4]
y3 = r[5]
x0 = r[6]
y0 = r[7]

if __name__ == '__main__':

    root = Tk()
    root.title("Ferma")
    root.geometry("1000x600")

    canvas = Canvas(bg="black", width=1000, height=600)
    canvas.pack(anchor=CENTER, expand=1)

    canvas.create_line(k*x1-t, -k*y1-p, k*x2-t, -k*y2-p, fill="blue")
    canvas.create_line(k*x1-t, -k*y1-p, k*x3-t, -k*y3-p, fill="blue")
    canvas.create_line(k*x2-t, -k*y2-p, k*x3-t, -k*y3-p, fill="blue")
    canvas.create_line(k*x1-t, -k*y1-p, k*x0-t, -k*y0-p, fill="red")
    canvas.create_line(k*x2-t, -k*y2-p, k*x0-t, -k*y0-p, fill="red")
    canvas.create_line(k*x3-t, -k*y3-p, k*x0-t, -k*y0-p, fill="red")
    canvas.create_line(0 - t, -2000 - p, 0 - t, 2000 - p, fill="white")
    canvas.create_line(2000 - t, 0 - p, -2000 - t, 0 - p, fill="white")

    canvas.create_oval([x1*k - t - R, -y1*k - p - R], [x1*k - t + R, -y1*k - p + R], fill="white")
    canvas.create_oval([k*x2-t - R, -k*y2-p - R], [k*x2-t + R, -k*y2-p + R], fill="white")
    canvas.create_oval([x3 * k - t - R, -y3 * k - p - R], [x3 * k - t + R, -y3 * k - p + R], fill="white")
    canvas.create_oval([x0 * k - t - R, -y0 * k - p - R], [x0 * k - t + R, -y0 * k - p + R], fill="green")

    root.mainloop()