TEX=pdflatex
PAPER=p02.tex
BIB_FILE=references.bib
PAPER_BASENAME=$(basename $(PAPER))


.PHONY = all All clean mf

all:
	@$(MAKE) --no-print-directory All

All: $(PAPER_BASENAME).pdf

clean:
	@for file in *; do \
        case $$file in (Makefile|*.tex|*.bst|*.bib|*.pdf): continue ;; (*) rm -rf "$$file" ;; esac; \
    done

mf:
	for file in *; do \
        case $$file in (*.mf) mf "$$file" ;; esac; \
    done

$(PAPER_BASENAME).aux: $(PAPER)
	-$(TEX) $(PAPER)

$(PAPER_BASENAME).bbl: $(PAPER_BASENAME).aux $(BIB_FILE)
	bibtex $(PAPER_BASENAME).aux

$(PAPER_BASENAME).pdf: $(PAPER) $(BIB_FILE)
	@$(MAKE) $(PAPER_BASENAME).bbl
	@$(MAKE) mf
	-$(TEX) $(PAPER)
	$(TEX) $(PAPER)