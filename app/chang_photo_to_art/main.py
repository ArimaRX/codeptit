import tkinter as tk
import PIL
from PIL import ImageTk, Image
from tkinter import filedialog
import model
import numpy as np
import os
import tensorflow as tf
os.environ["CUDA_VISIBLE_DEVICES"] = "-1"
window = tk.Tk()
def openFile():
    # must have global to show image
    #global photo
    global art_af
    file_path = filedialog.askopenfilename(initialdir='C:\\',
                                           filetypes=(('JPG Image', '*.jpg'), ('PNG Image', '*.png')))
    # import photo
    photo_ori = Image.open(file_path, 'r')
    #zoom = 0.3
    #photo_ori_x_size, photo_ori_y_size = tuple([int(zoom * x) for x in photo_ori.size])
    #photo = ImageTk.PhotoImage(photo_ori.resize((photo_ori_x_size, photo_ori_y_size)))
    #photo = ImageTk.PhotoImage(photo_ori)
    #image_view.configure(image=photo)

    #import gan photo
    photo_af = model.preprocess_photo(photo_ori)
    gan_gen = model.Generator()
    gan_gen.load_weights('ckpt_monet_generator.h5')
    art_pre = gan_gen(photo_af)
    art_pre = (art_pre + 1) * 127.5
    art_pre = np.array(art_pre).astype(dtype=np.uint8)
    art_pre = np.reshape(art_pre, (256, 256, 3))
    #art_pre = tf.image.resize(art_pre, [500, 500, 3])
    #art_pre = np.array(art_pre)
    art_ori = Image.fromarray(art_pre)
    art_ori_x_size, art_ori_y_size = tuple([int(2 * x) for x in art_ori.size])
    if art_ori_x_size > art_ori_y_size: art_af = ImageTk.PhotoImage(art_ori.resize((int(1.5 * art_ori_x_size), art_ori_y_size), Image.Resampling.LANCZOS))
    else: art_af = ImageTk.PhotoImage(art_ori.resize((art_ori_x_size,int(1.3 * art_ori_y_size)), Image.Resampling.LANCZOS))
    image_gan_view.configure(image=art_af)
    lb1.destroy(); lb2.destroy(); lb3.destroy(); lb4.destroy()

lb1 = tk.Label(window, text='+ Ứng dụng được xây dựng bởi nhóm 2', font=('Arial', 25))
lb1.pack(side=tk.TOP, anchor='w')
lb2 = tk.Label(window, text='+ Đây là ứng dụng chuyển ảnh thành tranh vẽ', font=('Arial', 25))
lb2.pack(side=tk.TOP, anchor='w')
lb3 = tk.Label(window, text='+ Để có trải nghiệm tốt nhất, bạn hãy sử dụng tranh phong cảnh', font=('Arial', 25))
lb3.pack(side=tk.TOP, anchor='w')
lb4 = tk.Label(window, text='+ Ấn nút dưới đây để chọn ảnh', font=('Arial', 25))
lb4.pack(side=tk.TOP, anchor='w')
tk.Button(window, text='Chọn ảnh', font=('Arial', 25), command=openFile).pack(side=tk.TOP)
#image_view = tk.Label(window,text='please choose a image!')
#image_view.pack(side=tk.LEFT)
image_gan_view = tk.Label(window,text='Đang chờ...', font=('Arial', 25))
image_gan_view.pack(side=tk.TOP)
window.mainloop()
