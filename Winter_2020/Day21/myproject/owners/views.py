import myproject
from flask import Blueprint, render_template, redirect, url_for
from myproject import db
from myproject.models import Owner
from myproject.owners.forms import AddForm


owners_blueprints = Blueprint(
    'owners', __name__, template_folder='templates/owners')


@owners_blueprints.route('/add', methods=['GET', 'POST'])
def add():
    form = AddForm()
    if form.validate_on_submit():
        id = form.id.data
        name = form.name.data
        new_owner = Owner(name, id)
        db.session.add(new_owner)
        db.session.commit()
        return redirect(url_for('puppies.list'))
    return render_template('addowner.html', form=form)
