import sys
import os
import multiprocessing as mp

MAX_WORKERS = max(mp.cpu_count()-1, 1)
njobs = 10
OUTDIR= "python_output"

if __name__ == "__main__":
    pool = mp.Pool(MAX_WORKERS)

    if len(sys.argv) > 1:
        njobs = sys.argv[1]

    procs = list()
    for i in range(njobs):
        p = mp.Process(target=os.system, args=["./hello %s > %s "%(str(i+1), os.path.join(OUTDIR, "python_job_%s.txt"%str(i+1)))])
        p.start()
        procs.append(p)
    
    for p in procs:
        p.join()