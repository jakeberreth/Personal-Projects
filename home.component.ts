import { Component } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})

export class HomeComponent {
  title = 'home';

  constructor(private router: Router) { }

  onClickPractice() {
    this.router.navigate(['practice']);
  }

  onClickGetStarted() {
    this.router.navigate(['login']);
  }

  onClickProgress() {
    this.router.navigate(['progress-page']);
  }
}
