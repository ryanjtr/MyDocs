Github
======

.. contents::
    :depth: 2

Working space
Stage area and git local

Installation
-------------------

**For Ubuntu**

.. code-block:: bash

    sudo apt install git

Commands
--------------

.. note::

    If first time use github, you must commands below

.. code-block:: bash

    git config --global user.name "John"

    git config --global user.mail "nguyevana@gmail.com"

    git config credential.helper store # to store user name and password to your computer
    
Initiate git local

.. code-block:: bash

    git init

Add all file to local

.. code-block:: bash

    git add .

Commit code to local

.. code-block:: bash

    git commit -m "message"


Link to remote repository

.. code-block:: bash

    git remote add origin <Url_repo>

Push code to branch ``master`` of remote repository, later then just use ``git push``

.. code-block:: bash

    git push -u origin master


Update code from branch ``master`` to local

.. code-block:: bash

    git pull origin master

Change to another version (version: code committed to git remote)

.. code-block:: bash

    git checkout <commit_id>

Create a new branch and move to it (-b: create a new branch)

.. code-block:: bash

    git checkout -b <branch_name>

Merge a branch to master

.. code-block:: bash

    git merge <branch_name>

List branch 

.. code-block:: bash 

    git branch -a

Assumed you committed c1 c2 c3 c4 c5. If you use the command below, then we will return to c2, code in c3 c4 c5 will be deleted (as never exist)

.. code-block:: bash

    git reset --hard <id_c2>

Force to push code to remote due to difference in commit history (not recommend)

.. code-block:: bash

    git push -f

Show id commit

.. code-block:: bash

    git log

Return to a commit in history

.. code-block:: bash

    git revert <id_commit>



