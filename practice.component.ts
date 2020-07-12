import { Component } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'practice',
  templateUrl: './practice.component.html',
  styleUrls: ['./practice.component.css']
})
export class PracticeComponent {
  constructor(private router: Router) { }

  onClickDailyPractice() {
    this.router.navigate(['daily-practice']);
  }

  onClickChallenges() {
    this.router.navigate(['challenges']);
  }




}
