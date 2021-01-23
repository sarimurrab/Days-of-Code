from flask import Blueprint, render_template, redirect, url_for
from myproject import db
from myproject.models import Puppy
from myproject.puppies.forms import AddForm, DelForm


puppies_blueprint = Blueprint(
    'puppies', __name__, template_folder='templates/puppies')


@puppies_blueprint.route('/add', methods=['GET', 'POST'])
def add():
    form = AddForm()

    if form.validate_on_submit():
        name = form.name.data
        new_pup = Puppy(name)
        db.session.add(new_pup)
        db.session.commit()

        return redirect(url_for('puppies.list'))
    return render_template('add.html', form=form)


@puppies_blueprint.route('/list')
def list_pup():
    puppies = Puppy.query.all()
    return render_template('list.html', puppies=puppies)


@puppies_blueprint.route('/delete', methods=['GET', 'POST'])
def del_pup():
    form = DelForm()
    if form.validate_on_submit():
        id = form.id.data
        id_obj = Puppy.query.get(id)
        db.session.delete(id_obj)
        db.session.commit()
        return redirect(url_for('puppies.list'))
    return render_template('delete.html', form=form)
