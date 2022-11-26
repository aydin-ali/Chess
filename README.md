# Chess

### [CS 246]
...\
Chess engine\
...

## Git branching

Creating and switching to a new branch
1. `git branch <branch-name>`
2. `git checkout <branch-name>`

Pushing the branch
1. `git push -u origin <branch-name>` 
2. Afterwards, just make the PR on Github and merge yourself

List all remote branches
1. `git branch -a`

Deleting branches
1. If everything has been merged, the branch can be safely deleted with `git branch -d <branch-name>` 
2. Otherwise, you can use `git branch -D <branch-name>` to delete a branch which hasn't been fully merged\

Or just delete branches after they've been merged through Github.
