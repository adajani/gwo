#  Makefile
#
#  Author:
#       Ahmad Dajani <eng.adajani@gmail.com>
#
#  Copyright (c) 2020 Ahmad Dajani
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.

CC=g++
CPPFLAGS=-g -std=c++11 -Wall -I$(INC_DIR)

GWO_SRC_DIR=./src
BNCH_SRC_DIR=./benchmark
BLD_DIR=./build
INC_DIR=./include

GWO_SRC=$(wildcard $(GWO_SRC_DIR)/*.cc)
GWO_OBJ=$(GWO_SRC:$(GWO_SRC_DIR)/%.cc=$(BLD_DIR)/%.o)
BNCH_SRC=$(wildcard $(BNCH_SRC_DIR)/*.cc)
BNCH_OBJ=$(BNCH_SRC:$(BNCH_SRC_DIR)/%.cc=$(BLD_DIR)/%.o)

$(BLD_DIR)/gwo: $(GWO_OBJ) $(BNCH_OBJ)
	$(CC) $^ -o $@

$(BLD_DIR)/%.o: $(GWO_SRC_DIR)/%.cc
	$(CC) $(CPPFLAGS) -c $< -o $@

$(BLD_DIR)/%.o: $(BNCH_SRC_DIR)/%.cc
	$(CC) $(CPPFLAGS) -c $< -o $@


clean:
	@$(RM) -rf $(BLD_DIR)/*.o
	@$(RM) -rf $(BLD_DIR)/gwo
