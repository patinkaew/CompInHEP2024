import awkward as ak

import coffea
from coffea.nanoevents import NanoEventsFactory, NanoAODSchema

import hist

import matplotlib.pyplot as plt
import mplhep

mplhep.style.use("ROOT")

NanoAODSchema.warn_missing_crossrefs = False

fname = "DYJetsToLL.root"
events = NanoEventsFactory.from_root(
    fname,
    schemaclass=NanoAODSchema,
).events()

selection = events["HLT", "IsoMu24"]

h = hist.new.Regular(25, 0, 50, name="pileup", label="pileup").Int64()
h.fill(pileup=ak.flatten(events[selection]["PV", "npvs"],axis=None))

fig, ax = plt.subplots()
h.plot(ax=ax)
ax.set_ylabel("events")

fig.savefig("pileup_coffea.pdf")
fig.savefig("pileup_coffea.png")
