						else if (match(lines[d], "if") && adj[blocks[d]].size() > 2)
							adj[blocks[d]].erase(*prev_itr);