Github
======

.. contents::
    :depth: 3

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


Write access to repository not granted. fatal: unable to access
---------------------------------------------------------------------------

Visit this `link stackoverflow <https://stackoverflow.com/questions/70538793/remote-write-access-to-repository-not-granted-fatal-unable-to-access>`_

Initiate git local
~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    git init

.. note::

    If you mistakenly use ``git init`` in wrong the folder, then on Windows, you can invoke 
    
    .. code-block:: bash
        
        dir /a
        
    to find ``.git`` file. Then delete it with 

    .. code-block:: bash

        rmdir /s /q .git

Git ignore
~~~~~~~~~~~~~~~~~~~~~~

Git will not ignore files/folders that have already been tracked, even if they have been added to ``.gitignore``

You have to remove files/folders from Git's tracking status, here i will remove folder ``Debug``:

.. code-block:: bash

    git rm -r --cached Debug

Then, commit the changes, and Git will ignore the Debug folder according to the ``.gitignore``.

Add all file to local
~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    git add .

Commit code to local
~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    git commit -m "message"


Link to remote repository
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    git remote add origin <Url_repo>

Push code to branch
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Push code to branch ``master`` of remote repository, later then just use ``git push``

.. code-block:: bash

    git push -u origin master


Update code from branch to local
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Update code from branch ``master`` to local

.. code-block:: bash

    git pull origin master

Change to another version (version: code committed to git remote)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    git checkout <commit_id>

Create a new branch and move to it (-b: create a new branch)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    git checkout -b <branch_name>

Merge a branch to master
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    git merge <branch_name>

List branch 
~~~~~~~~~~~~~~~~

.. code-block:: bash 

    git branch -a

Assumed you committed c1 c2 c3 c4 c5. If you use the command below, then we will return to c2, code in c3 c4 c5 will be deleted (as never exist)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    git reset --hard <id_c2>

Force to push code to remote due to difference in commit history (not recommend)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    git push -f

Show id commit
~~~~~~~~~~~~~~~~~

.. code-block:: bash

    git log

Return to a commit in history
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    git revert <id_commit>

Git clone
~~~~~~~~~~~~~~

If you don't need the entire commit history, you can perform a shallow clone, which only fetches the latest state of the repository. Use the --depth option:

.. code-block:: bash

    git clone --recurse-submodules --depth 1 https://github.com/cetic/6lbr.git

Recover code from git repository
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

If you want to change current code and recover it from git repository

.. code-block:: bash

    git fetch --all

.. code-block:: bash

    git reset --hard origin/<branch-name>

