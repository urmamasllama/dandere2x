import time

from dandere2x import Dandere2x

start = time.time()

d = Dandere2x('config.ini')
d.run_concurrent()

end = time.time()

print("\n duration:" + str(time.time() - start))

# d.difference_only()

# d.merge_only()

# running corrections before a frame and after?
