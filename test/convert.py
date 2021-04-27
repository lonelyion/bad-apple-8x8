import cv2

TOTAL = 4861
i = 0
while i < TOTAL:
    s = "%04d" % i
    print(s)
    img = cv2.imread("./192x/ba" + s + ".jpg")
    new_img = cv2.resize(img, (8, 8), interpolation=cv2.INTER_LINEAR)
    gray = cv2.cvtColor(new_img, cv2.COLOR_RGB2GRAY)
    ret, binary = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_TRIANGLE)
    cv2.imwrite("./8x/" + str(i) + ".jpg", binary)
    i = i + 1
